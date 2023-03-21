int sum(initializer_list<int> iil) {
    int res = 0;
    for (auto i : iil) res += i;
    return res;
}
