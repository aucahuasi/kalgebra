// This file was generated by qlalr - DO NOT EDIT!
#include "expressiontable_p.h"

const char *const ExpressionTable::spell [] = {
  "end of file", "+", "-", "*", ":=", "..", "/", "^", "identifier", "block", 
  "->", "?", ",", "(", ")", "{", "}", "value", "=", "|", 
  0, 0, 
#ifndef QLALR_NO_EXPRESSIONTABLE_DEBUG_INFO
"Program", "Expression", "Block", "Id", "Value", "PrimaryExpression", "PrimaryExpressionExt", "FBody", 
  "Parameters", "BVars", "BValue", "Limits", "BVarList", "$accept"
#endif // QLALR_NO_EXPRESSIONTABLE_DEBUG_INFO
};

const int ExpressionTable::lhs [] = {
  22, 24, 25, 26, 26, 27, 28, 28, 23, 23, 
  27, 27, 29, 29, 27, 23, 23, 23, 23, 23, 
  23, 23, 23, 23, 23, 30, 30, 32, 32, 31, 
  31, 34, 34, 33, 35};

const int ExpressionTable:: rhs[] = {
  1, 1, 1, 1, 1, 1, 3, 1, 1, 2, 
  4, 3, 1, 3, 4, 3, 2, 2, 3, 3, 
  3, 3, 3, 3, 3, 1, 3, 1, 3, 1, 
  3, 3, 3, 3, 2};


#ifndef QLALR_NO_EXPRESSIONTABLE_DEBUG_INFO
const int ExpressionTable::rule_info [] = {
    22, 23
  , 24, 9
  , 25, 8
  , 26, 17
  , 26, 25
  , 27, 26
  , 28, 13, 23, 14
  , 28, 27
  , 23, 28
  , 23, 25, 27
  , 27, 25, 13, 29, 14
  , 27, 25, 13, 14
  , 29, 30
  , 29, 30, 19, 31
  , 27, 24, 15, 30, 16
  , 23, 31, 10, 23
  , 23, 2, 23
  , 23, 11, 23
  , 23, 23, 1, 23
  , 23, 23, 2, 23
  , 23, 23, 3, 23
  , 23, 23, 6, 23
  , 23, 23, 7, 23
  , 23, 23, 11, 23
  , 23, 26, 4, 23
  , 30, 23
  , 30, 30, 12, 23
  , 32, 26
  , 32, 26, 18, 33
  , 31, 32
  , 31, 13, 34, 14
  , 34, 32, 12, 32
  , 34, 34, 12, 32
  , 33, 28, 5, 28
  , 35, 22, 0};

const int ExpressionTable::rule_index [] = {
  0, 2, 4, 6, 8, 10, 12, 16, 18, 20, 
  23, 28, 32, 34, 38, 43, 47, 50, 53, 57, 
  61, 65, 69, 73, 77, 81, 83, 87, 89, 93, 
  95, 99, 103, 107, 111};
#endif // QLALR_NO_EXPRESSIONTABLE_DEBUG_INFO

const int ExpressionTable::action_default [] = {
  0, 30, 0, 0, 1, 5, 8, 9, 0, 6, 
  2, 3, 0, 0, 0, 4, 0, 16, 0, 0, 
  0, 0, 0, 0, 19, 22, 21, 23, 24, 20, 
  0, 26, 0, 0, 15, 27, 5, 10, 6, 0, 
  0, 13, 12, 11, 0, 14, 5, 28, 0, 0, 
  29, 0, 0, 0, 34, 0, 7, 0, 0, 0, 
  32, 0, 31, 33, 35, 0, 25, 30, 6, 18, 
  17};

const int ExpressionTable::goto_default [] = {
  8, 31, 3, 5, 9, 6, 7, 40, 32, 2, 
  1, 50, 58, 0};

const int ExpressionTable::action_index [] = {
  114, -22, -5, -9, 94, 52, -22, -22, 19, 18, 
  -22, -22, 114, 114, 114, -22, 114, 94, 114, 114, 
  114, 114, 114, 114, 38, 1, -4, -22, 73, 38, 
  114, 94, 5, 114, -22, 94, -3, -22, -22, 100, 
  -13, 4, -22, -22, 17, -22, -22, -16, 3, 29, 
  -22, 2, 75, 39, -22, 135, -22, -12, 0, 10, 
  -22, 7, -22, -22, -22, 114, 94, -8, 45, 94, 
  -22, 

  1, -14, -14, -14, -14, 29, -14, -14, -14, -14, 
  -14, -14, 27, 8, 18, -14, 7, -14, 10, 9, 
  6, 2, 4, 5, -14, -14, -14, -14, -14, -14, 
  -14, -14, -14, 0, -14, -14, -14, -14, -14, -8, 
  -14, -14, -14, -14, 26, -14, -14, -14, 12, 20, 
  -14, -14, 11, 14, -14, -14, -14, -14, -14, 35, 
  -14, 40, -14, -14, -14, 3, -14, -14, -14, -14, 
  -14};

const int ExpressionTable::action_info [] = {
  59, 43, 49, 21, 59, 16, 30, 53, 21, 0, 
  39, 11, 61, 0, 62, 11, 33, 33, 11, 64, 
  15, 34, 65, 44, 15, 11, 0, 15, -28, 0, 
  48, 0, 0, 0, 15, 0, 49, 11, 10, 0, 
  0, 20, 52, 0, 19, 21, 15, 11, 10, 65, 
  0, 0, 52, 0, 0, -28, 15, -28, 0, 0, 
  11, 10, 0, 49, 0, 39, 0, 0, 0, 15, 
  0, 0, 0, 0, 18, 23, 20, 14, 0, 19, 
  21, 0, 0, 11, 10, 0, 13, 0, 12, 0, 
  0, 0, 15, 0, 0, 18, 23, 20, 0, 0, 
  19, 21, 14, 0, 0, 22, 0, 0, 11, 10, 
  0, 13, 0, 12, 42, 0, 14, 15, 0, 0, 
  0, 0, 11, 10, 0, 13, 0, 12, 0, 0, 
  0, 15, 0, 0, 0, 0, 18, 23, 20, 0, 
  0, 19, 21, 0, 0, 0, 22, 0, 0, 56, 
  0, 0, 0, 0, 0, 0, 0, 

  41, 35, 4, 27, 66, 28, 29, 26, 17, 69, 
  25, 24, 55, 0, 0, 46, 47, 36, 38, 70, 
  54, 0, 57, 36, 38, 0, 51, 0, 55, 46, 
  47, 68, 36, 38, 37, 45, 0, 67, 46, 47, 
  0, 0, 0, 46, 47, 60, 0, 0, 0, 0, 
  63, 0, 0, 0};

const int ExpressionTable::action_check [] = {
  12, 14, 18, 7, 12, 10, 15, 5, 7, -1, 
  13, 8, 12, -1, 14, 8, 12, 12, 8, 0, 
  17, 16, 4, 19, 17, 8, -1, 17, 10, -1, 
  13, -1, -1, -1, 17, -1, 18, 8, 9, -1, 
  -1, 3, 13, -1, 6, 7, 17, 8, 9, 4, 
  -1, -1, 13, -1, -1, 10, 17, 12, -1, -1, 
  8, 9, -1, 18, -1, 13, -1, -1, -1, 17, 
  -1, -1, -1, -1, 1, 2, 3, 2, -1, 6, 
  7, -1, -1, 8, 9, -1, 11, -1, 13, -1, 
  -1, -1, 17, -1, -1, 1, 2, 3, -1, -1, 
  6, 7, 2, -1, -1, 11, -1, -1, 8, 9, 
  -1, 11, -1, 13, 14, -1, 2, 17, -1, -1, 
  -1, -1, 8, 9, -1, 11, -1, 13, -1, -1, 
  -1, 17, -1, -1, -1, -1, 1, 2, 3, -1, 
  -1, 6, 7, -1, -1, -1, 11, -1, -1, 14, 
  -1, -1, -1, -1, -1, -1, -1, 

  8, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
  1, 1, 1, -1, -1, 3, 4, 3, 4, 1, 
  6, -1, 10, 3, 4, -1, 6, -1, 1, 3, 
  4, 4, 3, 4, 5, 9, -1, 10, 3, 4, 
  -1, -1, -1, 3, 4, 10, -1, -1, -1, -1, 
  10, -1, -1, -1};

