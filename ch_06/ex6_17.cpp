bool hasUpper(const string &s) {
    for (auto &c : s)
        if (isupper(c)) return true;
    return false;
}

const string &makeLower(string &s) {
    for (auto &c : s)
        if (isupper(c)) c = tolower(c);
    return s;
}
