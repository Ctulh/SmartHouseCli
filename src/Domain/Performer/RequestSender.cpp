//
// Created by ctuh on 2/1/23.
//

#include "Domain/Performer/RequestSender.hpp"

#include "Inet/Socket.hpp"
#include "Inet/InetAddress.hpp"
#include <chrono>
#include "SocketReader/SocketReader.hpp"
#include "SocketPoller.hpp"

std::string RequestSender::send(std::string const& deviceAddr, std::string const& request) {
    InetAddress inetAddr(deviceAddr, 55443);
    auto socket = std::make_shared<Socket>(inetAddr, SOCK_TYPE::TCP);
    auto tcpConnection = std::make_shared<TcpConnection>(socket);
    auto connectStatus = socket->connect();
    auto sendStatus = socket->send(request.c_str(), request.size());


    std::string response;

    ReceiveMessageCallback receiveResponseCallback = [&response](auto responseMessage){
        response = responseMessage;
    };

    SocketPoller socketPoller(1, 100);
    socketPoller.setReceiveMessageCallback(receiveResponseCallback);
    socketPoller.add(tcpConnection);

    socketPoller.poll();

    return response;
}
