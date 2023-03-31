#include<iostream>
#include<queue>
#include<functional>

struct Student
{
    std::string name;
    double gpa;
};

int main(int argc, char const *argv[])
{
    std::priority_queue<Student
        ,std::vector<Student>
        ,std::function<bool(const Student&, const Student&)>> pq(
            [](const Student& a, const Student& b) -> bool { return a.gpa > b.gpa; }
        );

    pq.push({"a1", 4.0});
    pq.push({"a2", 3.0});
    pq.push({"a3", 3.75});
    pq.push({"a4", 2.0});

    while(!pq.empty())
    {
        std::cout << pq.top().name << ": " << pq.top().gpa << std::endl;
        pq.pop();
    }

    return 0;
}
