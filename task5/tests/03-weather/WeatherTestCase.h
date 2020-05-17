
#pragma once

#include <gtest/gtest.h>
#include "cpr/cpr.h"
#include "WeatherMock.h"

class WeatherTestCase : public ::testing::Test {
public:
    WeatherMock weather;
    
    cpr::Response city1;
    cpr::Response city2;
    cpr::Response error_401;

    
    void SetUp() override;
};



