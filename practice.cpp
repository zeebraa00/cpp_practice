#include <iostream>

using namespace std;

class Parent {
    private:
        const int var; // private에 선언하면 class 내부에서만 접근 가능하다.

    public:
        Parent(int); // 생성자
        ~Parent(); // 소멸자
        void func();
        int getVar() { // private이므로 내부 함수를 이용해 값을 가져오고(get), 설정한다(set).
            return var;
        }
};

void Parent::func() {
    cout << "I am a func!" << endl;
}

Parent::Parent(int var) : var(var) // Parent의 생성자에 파라미터 전달
{
    cout << "I am a constructor of Parent!" << endl;
    // this->var = var; // 생성자에서 초기화
}

Parent::~Parent() { // Parent의 소멸자
    cout << "I am a destructor of Parent!" << endl;
}

class Child : public Parent { // Parent를 상속받은 Child 클래스 선언
    public:
        Child(int var) :
        Parent(var) // 이렇게 하면 Child의 생성자 실행 전에 부모 컴포넌트의 const 형 변수를 초기화할 수 있다.   
        {
            cout << "I am a constructor of Child!" << endl;
        }
        ~Child() {
            cout << "I am a destructor of Child!" << endl;
        }
        void func2() {
            cout << "I am a func2!" << endl;
        }

        void func() {
            cout << "I am a func made by Child!" << endl;
        }
};


class Animal {
    private:
        string name;

    public:
        virtual void sound() const = 0; // const를 이용해서 반드시 상속받아야 하는 함수임을 선언.
};

class Dog : public Animal {
    public:
        virtual void sound() const { // 반드시 상속해줘야 하는 함수이므로 const를 써줘야 함
            cout << "멍멍\n";
        }
};

class Cat : public Animal {
    public:
        virtual void sound() const {
            cout << "야옹\n";
        }
};

class Duck : public Animal {
    public:
        virtual void sound() const {
            cout << "빽빽\n";
        }
        virtual void swim() {
            cout << "수영중\n";
        }
};

int main() {

    // Dog *dog = new Dog();
    // Cat *cat = new Cat();
    // Duck *duck = new Duck();

    Animal *dog = new Dog(); // 클래스 추상화
    Animal *cat = new Cat();
    Animal *duck = new Duck();

    dog->sound(); // 부모 노드에 선언이 되어있는 함수의 경우, const를 이용해서 자식 노드의 함수로 오버라이딩 해야 함.
    cat->sound();
    duck->sound();
    ((Duck *)duck)->swim(); // swim()처럼 부모 노드에 없는 함수의 경우, 명시적 캐스팅을 통해서 접근 가능.

    Parent *p1 = new Parent(1818); 
    cout << p1->getVar() << endl;

    int temp(10); // int temp = 10; 와 같은 뜻임
    cout << temp << endl;


    Child *c1 = new Child(18181818);
    // Parent p2;

    c1->func();
    c1->func2();

    delete p1;
    delete c1;
    delete dog;
    delete cat;
    delete duck;
    return 0;
}