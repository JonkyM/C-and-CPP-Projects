#include <string>
#include "StackType.h"

using namespace std;

int WellFormedParExp(string exp) {
    StackType<char> ParStack;
    int pairCount = 0;
    
    for(int i = 0; i < exp.size(); i++) {
        char par = exp[i];

        if (par == '(')
            ParStack.Push(')');
        else if (par == '[')
            ParStack.Push(']');
        else if (par == '{')
            ParStack.Push('}');

        else if (par == ')') {
            if (ParStack.IsEmpty())
                return -1;
            if ((ParStack.Pop()) == ')')
                pairCount++;
            else
                return -1;
        }
        else if (par == ']') {
            if (ParStack.IsEmpty())
                return -1;
            if ((ParStack.Pop()) == ']')
                pairCount++;
            else
                return -1;
        }
        else if (par == '}') {
            if (ParStack.IsEmpty())
                return -1;
            if ((ParStack.Pop()) == '}')
                pairCount++;
            else
                return -1;
        }
    }
    if (ParStack.IsEmpty())
        return pairCount;
    else
        return -1;
}