#include "str_blob.h"

int main()
{
    StrBlob b1;
    {
        StrBlob b2{"a", "an", "the"};
        b1 = b2;
        b1.push_back("about");
    }
    return 0;
}
