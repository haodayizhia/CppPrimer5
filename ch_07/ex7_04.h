class Person {
   public:
    Person() = default;
    Person(std::string s1, std::string s2) : name(s1), adress(s2) {}

   private:
    std::string name;
    std::string adress;
};
