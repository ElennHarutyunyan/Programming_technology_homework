#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <utility>

// 1. Method chaining - House Builder
enum class Roof {Gable, Hip, Flat};

struct House {
    int walls = 0;
    Roof roof = Roof::Gable;
    bool pool = false;
};

class HouseBuilder {
public:
    HouseBuilder& walls(int n) {
        h.walls = n;
        return *this;
    }
    HouseBuilder& roof(Roof r) {
        h.roof = r;
        return *this;
    }
    HouseBuilder& pool(bool on) {
        h.pool = on;
        return *this;
    }
    House build() {
        if (h.walls < 1) throw std::logic_error ("Not a house!!!\n");
        return std::move (h);
    }
private:
    House h;
};

// 2. SQL Query builder
class Query {
public:
    Query& select(std::string d) { sel = d; return *this; }
    Query& from(std::string t) { tbl = t; return *this; }
    Query& where(std::string c) {
        conds.push_back(c);
        return *this;
    }
    Query& orderBy(std::string d) { ord = d; return *this; }

    std::string str() const {
        std::string result = "SELECT " + sel + " FROM " + tbl;
        if (!conds.empty()) {
            result += " WHERE ";
            for (size_t i = 0; i < conds.size(); ++i) {
                result += " " + conds[i]; // formatting continuation
            }
        }
        if (!ord.empty()) {
            result += " ORDER BY " + ord;
        }
        return result;
    }
private:
    std::string sel, tbl, ord;
    std::vector<std::string> conds;
};

// 3. HTML Element Builder
struct Node {
    std::string tag, text;
    std::vector <Node*> kids;

    ~Node() {
        for (auto kid : kids) delete kid;
    }
};

class HtmlBuilder {
public:
    explicit HtmlBuilder(std::string root) : n{ std::move(root), "", {} } {}

    HtmlBuilder& add(std::string tag, std::string text) {
        n.kids.push_back(new Node { std::move(tag), std::move(text), {} });
        return *this;
    }

    Node build() {
        return std::move(n);
    }
private:
    Node n;
};

int main() {
    House h = HouseBuilder().walls(4).roof(Roof::Gable).pool(true).build();
    std::cout << "House built successfully with " << h.walls << " walls!!\n";

    auto sql = Query().select("id, name").from("students").where("year = 4").where("gpa > 8").orderBy("name");
    std::cout << "SQL Query: " << sql.str() << "\n";

    Node list = HtmlBuilder("ul").add("li", "C++").add("li", "HTML").build();
    std::cout << "HTML Root Tag: " << list.tag << " with " << list.kids.size() << " children.\n";

    return 0;
}