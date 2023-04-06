#include <cstdio>
#include "my-string.hpp"

// TODO: Fill in these functions. Check the comments in my-string.hpp file.

MyString::~MyString()
{
    delete arr;
}

size_t MyString::GetLength()
{
    return length;
}

void MyString::Clear()
{
    length = 0;
}

void MyString::Insert(MyString *s, int idx)
{
    if (idx > length)
        return;

    int s_len = s->GetLength();
    char *backup = arr;
    if (NULL == (arr = (char *)realloc(arr, length + s_len)))
    {
        arr = backup;
        return;
    }
    
    for(int i = GetLength(); i>=idx; i--)
        arr[i+s_len] = arr[i];
    
    for (int i = 0; i < s_len; i++)
        arr[idx + i] = s->arr[i];

    length += s_len;
}

void MyString::Remove(int idx, int n)
{
    if (idx >= length)
        return;
    if (idx + n >= length)
    {
        length = idx;
        return;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (idx + n + i > length)
                break;
            arr[idx + i] = arr[idx + n + i];
        }
    }
    length -= n;
}
