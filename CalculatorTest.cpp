#include <gtest/gtest.h>
#include "Calculator.h"

TEST(CalculatorTest, BasicArithmetic) {
    Calculator e;
    EXPECT_EQ(e.evaluate("7 * 6"), 42);
    EXPECT_EQ(e.evaluate("7 + 6"), 13);
    EXPECT_EQ(e.evaluate("7 - 6"), 1);
    EXPECT_EQ(e.evaluate("7 / 6"), 1.16666666667);
}

TEST(CalculatorTest, BasicArithmeticNoSpace) {
    Calculator e;
    EXPECT_EQ(e.evaluate("7* 6"), 42);
    EXPECT_EQ(e.evaluate("7 +6"), 13);
    EXPECT_EQ(e.evaluate("7-6"), 1);
    EXPECT_EQ(e.evaluate("7/6"), 1.16666666667);
}

TEST(CalculatorTest, AdvancedArithmetic) {
    Calculator e;
    EXPECT_EQ(e.evaluate("7 + 6 * 6"), 43);
    EXPECT_EQ(e.evaluate("7 / 7 + 6 * 6"), 37);
    EXPECT_EQ(e.evaluate("7 - 7 + 6 * 6"), 36);
    EXPECT_EQ(e.evaluate("7 / 2 * 6"), 21);
    EXPECT_EQ(e.evaluate("(7 + 6) * 6"), 78);
    EXPECT_EQ(e.evaluate("7 / (7 + 6 * 6)"), 0.16279069767);
    EXPECT_EQ(e.evaluate("7 - (7 + 6) * 6"), -71);
    EXPECT_EQ(e.evaluate("-(7 - (7 + 6) * 6)"), 71);
}

TEST(CalculatorTest, BasicBinaryAlgebra) {
    Calculator e;
    EXPECT_EQ(e.evaluate("1 & 2"), 0);
    EXPECT_EQ(e.evaluate("7 & 6"), 6);
    EXPECT_EQ(e.evaluate("7 | 6"), 7);
}

TEST(CalculatorTest, AdvancedBinaryAlgebra) {
    Calculator e;
    EXPECT_EQ(e.evaluate("1 & 2 | 3"), 3);
    EXPECT_EQ(e.evaluate("1 & 2 | 7 | 6"), 7);
    EXPECT_EQ(e.evaluate("1 & 2 | 7 & 6"), 7);
    EXPECT_EQ(e.evaluate("7 & 6 | 1 & 2"), 7);
    EXPECT_EQ(e.evaluate("1 & (2 | 7) | 6"), 7);
    EXPECT_EQ(e.evaluate("1 & (2 | 7 & 6)"), 7);
    EXPECT_EQ(e.evaluate("7 & 6 | (1 & 2)"), 7);
}

TEST(CalculatorTest, BasicBooleanAlgebra) {
    Calculator e;
    EXPECT_EQ(e.evaluate("^1"), 0);
    EXPECT_EQ(e.evaluate("^0"), 1);
    EXPECT_EQ(e.evaluate("!1"), 0);
    EXPECT_EQ(e.evaluate("!0"), 1);
    EXPECT_EQ(e.evaluate("1 && 0"), 0);
    EXPECT_EQ(e.evaluate("0 || 1"), 1);
    EXPECT_EQ(e.evaluate("!1 && !0"), 0);
}