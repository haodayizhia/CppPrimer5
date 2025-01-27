#include <iostream>
#include <memory>

struct destination;
struct connection;
connection connect(destination *);
void disconnect(connection);
void end_connection(connection *p) { disconnect(*p); }

void f(destination &d) {
    connection *cptr = new connection(connect(&d));
    std::shared_ptr<connection> p(
        cptr, [](connection *p) -> void { disconnect(*p); });
}

int main(int argc, char *argv[]) { return 0; }
