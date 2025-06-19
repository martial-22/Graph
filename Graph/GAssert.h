#pragma once

void assertImpl(const char* cond, const char* file, int line);

#define GRAPH_ASSERT(cond)                            \
    do                                                \
    {                                                 \
        if (!(cond))                                  \
        {                                             \
            assertImpl(#cond, __FILE__, __LINE__); \
        }                                             \
    }                                                 \
    while (false)
