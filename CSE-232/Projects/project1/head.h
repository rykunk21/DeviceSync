#pragma once

string ToLower(string s);

bool ImprovedContains(string, string, bool *case_sens);

int ImprovedMatches(string, string, bool *case_sens);

int ImprovedFindFirstOf(string, string, bool *case_sens);

void ImprovedReplace(string &s, string, string, bool *case_sens);

int ImprovedNumberOfDifferences(string, string, bool *case_sens);

void test_toLower();

void test_ImprovedContains();

void test_ImprovedMatches();

void test_ImprovedFindFirstOf();

void test_ImprovedReplace();
