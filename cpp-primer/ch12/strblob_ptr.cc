#include<string>
#include<vector>
#include<stdexcept>
#include "str_blob.h"

#ifndef STRBLOB_PTR_H
#define STRBLOB_PTR_H

class StrBlobPtr {
    public:
        StrBlobPtr(): curr(0) {};
        StrBlobPtr(StrBlob &a, std::size_t sz = 0):
            wkpr(a.data), curr(sz) {};
        std::string& deref() const;
        StrBlobPtr& incr();
        bool operator!=(const StrBlobPtr &p) { return p.curr != curr; }
    private:
        std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string&) const;
        std::weak_ptr<std::vector<std::string>> wkpr;
        std::size_t curr;
};

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(std::size_t sz, const std::string &s) const
{
    auto ret = wkpr.lock();
    if (!ret)
        throw std::runtime_error("unbound StrBlobPtr");
    if (sz >= ret->size())
        throw std::out_of_range(s);
    return ret;
};

std::string& StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr()
{
    auto p = check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}

#endif
