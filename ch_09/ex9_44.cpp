std::string sub3(std::string s, std::string &oldVal, std::string &newVal) {
    for (size_t p = 0; p != s.size() - oldVal.size() + 1;) {
        size_t i = 0;
        if (s.substr(p,oldVal.size()) == oldVal) {
            s.replace(p,oldVal.size(),newVal);
            p += newVal.size();
        } else
            ++p;
    }
    return s;
}
