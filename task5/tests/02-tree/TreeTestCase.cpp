//
// Created by akhtyamovpavel on 5/1/20.
//


#include "TreeTestCase.h"
#include "Tree.h"
#include <boost/filesystem/operations.hpp>
#include <fstream>


using boost::filesystem::current_path;
using boost::filesystem::create_directory;
using boost::filesystem::remove_all;

void TreeTestCase::SetUpTestCase() {
    path = current_path().string() + "/f1";
    create_directory(path);
    
    std::string fname = path + "/f2.txt";   
    std::ofstream fout(fname);
    fout << "hi bro";
    fout.close();
    
    create_directory(path + "/f3"); 

}

void TreeTestCase::TearDownTestCase() {
    remove_all(path);
}



TEST_F(TreeTestCase, t1) {
    ASSERT_THROW(GetTree("f4", true), std::invalid_argument);
}


TEST_F(TreeTestCase, t2) {
    ASSERT_THROW(GetTree(path + "/f2.txt", true), std::invalid_argument);
}


TEST_F(TreeTestCase, t3) {
    ASSERT_NO_THROW(GetTree(path, true));
}


TEST_F(TreeTestCase, t4) {
    ASSERT_NO_THROW(GetTree(path, false));
}


TEST_F(TreeTestCase, t5) {
    ASSERT_EQ(GetTree(path, true), GetTree(path, true));
}

