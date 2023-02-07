
#pragma once

#include <gtest/gtest.h>

#include "Domain/Performers/XiaomiPerformer/ResponseParser.hpp"

TEST(ResponseParserTest, TestParseSimpleResponse) {
    std::string const response = R"({"id":1, "result":["ok"]})";

    ResponseParser responseParser(response);

    auto id = responseParser.getId();
    ASSERT_TRUE(id.has_value());
    ASSERT_EQ(id.value(), 1);

    auto result = responseParser.getResult();
    ASSERT_TRUE(result.has_value());

    auto resultValue = result.value();
    ASSERT_EQ(resultValue.size(), 1);
    ASSERT_EQ(resultValue[0], "ok");
}

TEST(ResponseParserTest, TestParseIncorrectReponse) {
    std::string const response = R"({"something": 1})";

    ResponseParser responseParser(response);

    auto id = responseParser.getId();
    ASSERT_FALSE(id.has_value());

    auto result = responseParser.getResult();
    ASSERT_FALSE(result.has_value());
}

TEST(ResponseParserTest, TestParseWithMoreThanOneValueInResult) {
    std::string const response = R"({"id":1, "result":["on", "smooth", 500]})";

    ResponseParser responseParser(response);

    auto id = responseParser.getId();
    ASSERT_TRUE(id.has_value());
    ASSERT_EQ(id.value(), 1);

    auto result = responseParser.getResult();
    ASSERT_TRUE(result.has_value());
    ASSERT_EQ(result.value().size(), 3);
    ASSERT_EQ(result.value()[0], "on");
    ASSERT_EQ(result.value()[1], "smooth");
    ASSERT_EQ(result.value()[2], "500");
}