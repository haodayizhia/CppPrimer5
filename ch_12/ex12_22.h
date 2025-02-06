class ConstStrBlobPtr {
   public:
    ConstStrBlobPtr() : curr(0) {}
    ConstStrBlobPtr(const StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    const std::string &deref() const;
    ConstStrBlobPtr &incr();
    bool operator!=(ConstStrBlobPtr &p) { return curr != p.curr; }

   private:
    std::shared_ptr<std::vector<std::string>> check(std::size_t,
                                                    const std::string &) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};

std::shared_ptr<std::vector<std::string>> ConstStrBlobPtr::check(
    std::size_t i, const std::string &msg) const {
    auto ret = wptr.lock();
    if (!ret) throw std::runtime_error("unbound StrBlobPtr");
    if (i >= ret->size()) throw std::out_of_range(msg);
    return ret;
}
const std::string &ConstStrBlobPtr::deref() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}
ConstStrBlobPtr &ConstStrBlobPtr::incr() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}
