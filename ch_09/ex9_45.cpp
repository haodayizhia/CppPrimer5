std::string addfix(std::string s,std::string pre, std::string su)
{
    s.insert(0,pre).append(su);
    return s;
}
