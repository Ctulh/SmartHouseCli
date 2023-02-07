//
// Created by ctuh on 2/1/23.
//

#include "Domain/Performers/XiaomiPerformer/RequestSender.hpp"

#include "Inet/Socket.hpp"
#include "Inet/InetAddress.hpp"
#include "SocketReader/SocketReader.hpp"
#include "SocketPoller.hpp"

namespace {
    const int POLL_TIMEOUT = 300;
    const int TRIES_AMOUNT = 3;
    const std::string SPACE_STRING = " ";
}

std::string RequestSender::send(std::string const& deviceAddr, std::string const& request) {
    InetAddress inetAddr(deviceAddr, 55443);
    auto socket = std::make_shared<Socket>(inetAddr, SOCK_TYPE::TCP);
    auto tcpConnection = std::make_shared<TcpConnection>(socket);
    SocketPoller socketPoller(1, ::POLL_TIMEOUT);
    socketPoller.add(tcpConnection);

    auto connectStatus = socket->connect();
    auto sendStatus = socket->send(request.c_str(), request.size());



    auto tryToPoll = [&socketPoller,  &socket]() -> std::string {
        std::string response;

        ReceiveMessageCallback receiveResponseCallback = [&response](auto responseMessage){
            response = responseMessage;
        };
        socketPoller.setReceiveMessageCallback(receiveResponseCallback);

        for(int i = 0; i < ::TRIES_AMOUNT; i++) {
            socketPoller.poll();
            if(not response.empty())
                break;
            socket->send(::SPACE_STRING.c_str(), SPACE_STRING.size());
        }
        return response;
    };


    auto firstMessage = tryToPoll();
    auto secondMessage = tryToPoll();

    auto response = firstMessage + secondMessage;
    return response;
}
