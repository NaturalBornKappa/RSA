#include "RSA.h"

RSA::RSA() {
    srand(static_cast <unsigned> (time(0)));
    generate_keys();
}

int RSA::get_private_key() {
    return this->d;
}


std::vector<int> RSA::get_public_keys() {
    std::vector<int> vec;
    vec.push_back(this->n);
    vec.push_back(this->e);
    return vec;
}


std::vector<int> RSA::chy(std::string string) {
    std::vector<int> ret;
    for (char letter : string) {
        int ascii = ord(letter);
        int crip = pow(ascii, this->e);
        crip = mod(crip, this->n);
        ret.push_back(crip);
        std::cout << letter << " " << crip << std::endl;
    }
    return ret;
}


void RSA::generate_keys() {
    this->p = generate_prime();
    this->q = generate_prime();
    this->n = p * q;
    int y = totient(p);
    int x = totient(q);
    this->phi_n = x * y;
    this->e = generate_e();
    this->d = generate_private_key();
}


int RSA::totient(int n) {
    if (isprime(n)) {
        return n - 1;
    }
}


bool RSA::isprime(int n) {
    if (n <= 1)  return false;
    if (n <= 3)  return true;

    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}


int RSA::generate_e() {
    while (true) {
        int generated = this->generate_random(2, phi_n);
        if (this->gcd(this->phi_n, generated) == 1) {
            return generated;
        }
    }
}

int RSA::gcd(int x, int y) {
    int rest = 1;
    while (y != 0) {
        rest = x % y;
        x = y;
        y = rest;
    }
    return x;
}


int RSA::ord(char c) {
    return (int)c;
}


char RSA::chr(int i) {
    return (char)i;
}


int RSA::generate_prime() {
    int e;
    do {
        e = generate_random();
    } while (!isprime(e));
    return e;
}

int RSA::generate_random(int from, int to) {
    return from + (rand() % to);
}

int RSA::mod(int x, int y) {
    if (x < y) {
        return x;
    }
    return x % y;
}


int RSA::generate_private_key() {
    int d = 0;
    while (mod(d * this->e, this->phi_n) != 1) {
        d++;
    }
    return d;
}

/***** MAIN *****/
int main() {
    RSA x = new RSA();

    int input = 0;
    while (input != 8) {
        std::cout << "\n" << "     " << "Mozliwe operacje : " << std::endl << std::endl;
        std::cout << "     " << "1.Generuj klucze" << std::endl;
        std::cout << "     " << "2.Wyswietlenie klucza prywatnego" << std::endl;
        std::cout << "     " << "3.Zapisz klucz do pliku:" << std::endl;
        std::cout << "     " << "4.Wpisz tekst jawny:" << std::endl;
        std::cout << "     " << "5." << std::endl;
        std::cout << "     " << "6.Exit" << std::endl;
        std::cout << "\n" << "     " << "Operacja ktora chcesz wykonac to : ";
       
        std::cin >> input;
        std::cout << std::endl;

    }

    if (input == 1) {
        std::cout << "Wygenerowano klucze" << std::endl;
        RSA x = new RSA();
    }
    else if (input == 1) {
        std::cout << "Twoj klucz prywatny: " << x.get_private_key() << std::endl;
    }
    else if (input == 2) {
        ;
    }
    else if (input == 3) {
        ;
    }
    else if (input == 4) {
        std::string txt;
        std::cin >> txt;
        RSA::chy(txt);

    }
    else if (input == 5) {

    }
    else if (input == 6) {
        return 0;
    }
    else {
        std::cout << "\n     Prosze podac poprawny numer operacji\n";
    };
}