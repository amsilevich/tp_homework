//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include "WeatherTestCase.h"
#include "WeatherMock.h"

using ::testing::Return;

void WeatherTestCase::SetUp() {
    city1.status_code = 200;
    city1.text = "{\"cod\":\"200\",\"message\":0.0036,\"cnt\":40,\"list\":[{\"dt\":1485799200,\"main\":{\"temp\":15.00}}]}";

    city2.status_code = 200;
    city2.text = {\"cod\":\"200\",\"message\":0.0036,\"cnt\":40,\"list\":[{\"dt\":1485799200,\"main\":{\"temp\":20.00}}]}";;

    error_401.status_code = 401;
}

TEST_F(WeatherTestCase, test1) {
    ASSERT_NO_THROW(weather.SetApiKey("not allow"));
}

TEST_F(WeatherTestCase, test2) {
    EXPECT_CALL(weather, Get("London"))
        .Times(1)
            .WillRepeatedly(Return(city1));
    ASSERT_NO_THROW(weather.Get("London"));
}

TEST_F(WeatherTestCase, test3) {
    EXPECT_CALL(weather, Get("London"))
        .Times(1)
            .WillRepeatedly(Return(city1));
    EXPECT_CALL(weather, Get("Moscow"))
        .Times(1)
            .WillRepeatedly(Return(city2));
    
    ASSERT_EQ(weather.GetDifferenceString("Moscow", "London"), "Weather in Moscow is warmer than in London by 5 degrees");
}

TEST_F(WeatherTestCase, test4) {
    EXPECT_CALL(weather, Get("London"))
        .Times(1)
            .WillRepeatedly(Return(city1));
    
    EXPECT_CALL(weather, Get("Moscow"))
        .Times(1)
            .WillRepeatedly(Return(city2));
    
    ASSERT_EQ(weather.GetDifferenceString("London", "Moscow"), "Weather in London is warmer than in Moscow by 5 degrees");
}

TEST_F(WeatherTestCase, test5) {
    EXPECT_CALL(weather, Get("ErrorCity"))
        .Times(1)
            .WillRepeatedly(Return(error_401));
    
    ASSERT_THROW(weather.GetResponseForCity("ErrorCity"), std::invalid_argument);
}
