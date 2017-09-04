// Copyright (c) 2014 baidu-rpc authors.
// Author: Ge,Jun (gejun@baidu.com)
// Date: 2010-12-04 11:59

#include <gtest/gtest.h>
#include "base/string_printf.h"

namespace {

class BaiduStringPrintfTest : public ::testing::Test{
protected:
    BaiduStringPrintfTest(){
    };
    virtual ~BaiduStringPrintfTest(){};
    virtual void SetUp() {
    };
    virtual void TearDown() {
    };
};

TEST_F(BaiduStringPrintfTest, sanity) {
    ASSERT_EQ("hello 1 124 world", base::string_printf("hello %d 124 %s", 1, "world"));
    std::string sth;
    ASSERT_EQ(0, base::string_printf(&sth, "boolean %d", 1));
    ASSERT_EQ("boolean 1", sth);
    
    ASSERT_EQ(0, base::string_appendf(&sth, "too simple"));
    ASSERT_EQ("boolean 1too simple", sth);
}

}
