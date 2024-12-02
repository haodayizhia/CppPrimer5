#include <iostream>
#include <memory>
#include <vector>

class strBlob {
   public:
    typedef std::vector<std::string>::size_type size_type;
    strBlob();
    strBlob(std::initializer_list<std::string> il);
    size_type size() const { return data->size(); };
    bool empty() const { return data->empty(); };
    void push_back(const std::string &t) { data->push_back(t); };
    void pop_back();
    std::string &front();
    std::string &back();
    const std::string &front();
    const std::string &back();

   private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};
strBlob::strBlob() : data(std::make_shared<std::vector<std::string>>()) {}
strBlob::strBlob(std::initializer_list<std::string> il)
    : data(std::make_shared<std::vector<std::string>>(il)) {}
void strBlob::check(size_type i, const std::string &msg) const {
    if (i >= data->size()) throw std::out_of_range(msg);
}
std::string &strBlob::front() {
    check(0, "front on empty strBlob");
    return data->front();
}
const std::string &strBlob::front() {
    check(0, "front on empty strBlob");
    return data->front();
}
std::string &strBlob::back() {
    check(0, "back on empty strBlob");
    return data->back();
}
const std::string &strBlob::back() {
    check(0, "back on empty strBlob");
    return data->back();
}
void strBlob::pop_back() {
    check(0, "pop_back on empty strBlob");
    data->pop_back();
}

int main(int argc, char *argv[]) {}
