class Person {
   public:
    string getName() const { return name; }
    string getAdress() const { return adress; }
    string name;
    string adress;
};
istream &read(istream &is, Person &item) {
    is >> item.name >> item.adress;
    return is;
}
ostream &print(ostream &os, const Person &item) {
    os << item.getName() << item.getAdress();
    return os;
}
