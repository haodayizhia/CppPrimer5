class StrBlobPtr {
   public:
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(const StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    std::string &deref() const;
    const StrBlobPtr &incr();
    bool operator!=(const StrBlobPtr &p) { return curr != p.curr; }

   private:
    std::shared_ptr<std::vector<std::string>> check(std::size_t,
                                                    const std::string &) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(
    std::size_t i, const std::string &msg) const {
    auto ret = wptr.lock();
    if (!ret) throw std::runtime_error("unbound StrBlobPtr");
    if (i >= ret->size()) throw std::out_of_range(msg);
    return ret;
}
const std::string &StrBlobPtr::deref() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}
const StrBlobPtr &StrBlobPtr::incr() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}
