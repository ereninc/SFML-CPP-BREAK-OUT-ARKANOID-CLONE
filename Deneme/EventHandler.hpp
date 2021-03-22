#pragma once
#include <functional>
#include <vector>

typedef std::function<void()> funcCalled;

typedef std::vector<funcCalled> funcList;