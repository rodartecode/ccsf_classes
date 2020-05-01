
#include <iostream>
#include <string>

using namespace std;

void reverseInt(int in);
void writeBackward(string in);
void writeBackward2(string in);

int main() {
        int one, two,  three, four;
        one = 1234;
        two = 9087;
        three = 55577554;
        four = 9182736;

        reverseInt(one);
        reverseInt(two);
        reverseInt(three);
        reverseInt(four);

        cout << endl << endl;

        string uno, dos, tres, cuatro;
        uno = " uno";
        dos = "doos";
        tres = "trreesss";
        cuatro = "quu uuatroo";

        writeBackward(uno);
        cout << endl;
        writeBackward(dos);
        cout << endl << endl;
        writeBackward2(tres);
        cout << endl;
        writeBackward2(cuatro);
        cout << endl;
}




void reverseInt(int in) {
        if (in < 10)
                cout << in << endl;
        else {
                cout << (in % 10);
                in /= 10;
                reverseInt(in);
        }
}




void writeBackward(string in) {
        cout << "Entered writeBackward with " << in << endl;

        int len = in.size();
        if (len > 0) {
                cout << "About to write last character of " << in << endl;
                cout << in[len - 1] << endl;
                writeBackward(in.substr(0, len - 1));
        }
        cout << "Exiting writeBackward with " << in << endl;
}




void writeBackward2(string in) {
        cout << "Entered writeBackward2 with " << in << endl;

        int len = in.size();
        if (len > 0) {
                writeBackward2(in.substr(1, len - 1));
                cout << "About to write first character of " << in << endl;
                cout << in[0] << endl;
        }
        cout << "Exiting writeBackward2 with " << in << endl;
}

/*

[jrodarte@hills ~]$ ./a.out
4321
7809
45577555
6372819


Entered writeBackward with  uno
About to write last character of  uno
o
Entered writeBackward with  un
About to write last character of  un
n
Entered writeBackward with  u
About to write last character of  u
u
Entered writeBackward with
About to write last character of

Entered writeBackward with
Exiting writeBackward with
Exiting writeBackward with
Exiting writeBackward with  u
Exiting writeBackward with  un
Exiting writeBackward with  uno

Entered writeBackward with doos
About to write last character of doos
s
Entered writeBackward with doo
About to write last character of doo
o
Entered writeBackward with do
About to write last character of do
o
Entered writeBackward with d
About to write last character of d
d
Entered writeBackward with
Exiting writeBackward with
Exiting writeBackward with d
Exiting writeBackward with do
Exiting writeBackward with doo
Exiting writeBackward with doos


Entered writeBackward2 with trreesss
Entered writeBackward2 with rreesss
Entered writeBackward2 with reesss
Entered writeBackward2 with eesss
Entered writeBackward2 with esss
Entered writeBackward2 with sss
Entered writeBackward2 with ss
Entered writeBackward2 with s
Entered writeBackward2 with
Exiting writeBackward2 with
About to write first character of s
s
Exiting writeBackward2 with s
About to write first character of ss
s
Exiting writeBackward2 with ss
About to write first character of sss
s
Exiting writeBackward2 with sss
About to write first character of esss
e
Exiting writeBackward2 with esss
About to write first character of eesss
e
Exiting writeBackward2 with eesss
About to write first character of reesss
r
Exiting writeBackward2 with reesss
About to write first character of rreesss
r
Exiting writeBackward2 with rreesss
About to write first character of trreesss
t
Exiting writeBackward2 with trreesss

Entered writeBackward2 with quu uuatroo
Entered writeBackward2 with uu uuatroo
Entered writeBackward2 with u uuatroo
Entered writeBackward2 with  uuatroo
Entered writeBackward2 with uuatroo
Entered writeBackward2 with uatroo
Entered writeBackward2 with atroo
Entered writeBackward2 with troo
Entered writeBackward2 with roo
Entered writeBackward2 with oo
Entered writeBackward2 with o
Entered writeBackward2 with
Exiting writeBackward2 with
About to write first character of o
o
Exiting writeBackward2 with o
About to write first character of oo
o
Exiting writeBackward2 with oo
About to write first character of roo
r
Exiting writeBackward2 with roo
About to write first character of troo
t
Exiting writeBackward2 with troo
About to write first character of atroo
a
Exiting writeBackward2 with atroo
About to write first character of uatroo
u
Exiting writeBackward2 with uatroo
About to write first character of uuatroo
u
Exiting writeBackward2 with uuatroo
About to write first character of  uuatroo

Exiting writeBackward2 with  uuatroo
About to write first character of u uuatroo
u
Exiting writeBackward2 with u uuatroo
About to write first character of uu uuatroo
u
Exiting writeBackward2 with uu uuatroo
About to write first character of quu uuatroo
q
Exiting writeBackward2 with quu uuatroo

*/