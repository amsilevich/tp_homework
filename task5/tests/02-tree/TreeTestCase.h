//
// Created by akhtyamovpavel on 5/1/20.
//


#pragma once

#include <gtest/gtest.h>
#include <boost/filesystem/path.hpp>

class TreeTestCase : public ::testing::Test {
public:    
    static void SetUpTestCase();
    static void TearDownTestCase();

    static std::string path; 
};

std::string TreeTestCase::path = "";
