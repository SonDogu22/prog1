/*
    make base_converter
    ./base_converter
    make base_converter && ./base_converter
*/

#include "base.h"

String characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
// todo: write purpose statement inclusive @param and @return
// Aufgabe 2a
/*
    @param number ist die Zahl, deren Länge berechnet wird.
    @param base hilft die Länge der Zahl zu berechnen und wird in der Formel verwendet.
    @return die Länge der Zahl als int, obwohl es als double berechnet wird. Das ermölicht uns "ceil",
    der unsere double Zahl in näerste große Zahl konvertiert.
*/
int length_for_base(int number, int base)
{
    if (number == 0)
        return 1;
    double needed_chars = log(number + 1) / log(base);
    int length = ceil(needed_chars);
    return length;
}
/*
    Gibt einen dynamisch allokierte String zurueck, der so viele Zeichen hat wie noetig sind um die Zahl in der Zielbasis darzustellen.
    @param number Zahl, die in der Zielbasis dargestellt wird.
    @param base Zielbasis, in der die Zahl number dargestellt werden soll.
    @return Eine Zeichenkette mit der noetigen Anzahl an Stellen mit '#' initialisiert.
*/
String get_string_for_number_and_base(int number, int base)
{
    int length = length_for_base(number, base);
    String s = xcalloc(sizeof(char), length + 1);
    // printf("length: %d\n", length);
    for (int i = 0; i < length; i++)
    {
        s[i] = '#';
    }
    return s;
}

/*
    Gibt die Zahl number in der Zielbasis als Zeichenkette zurueck.
    @param number Zahl, die in der Zielbasis dargestellt wird.
    @param base Zielbasis, in der die Zahl number dargestellt werden soll.
    @return String der die Zahl in der Zielbasis enthaelt.
*/
String convert_to_base(int number, int base)
{
    int len = length_for_base(number, base);
    String s = get_string_for_number_and_base(number, base);
    // s_set(s, 0, 'H');
    char c = s_get(characters, 12);
    s_set(s, 0, c);
    return s;
}

/*
    Schoen formatierte Ausgabe der Zahl, die zu konvertieren ist, sowie des Ergebnisses.
    @param number Zahl, die in der Zielbasis dargestellt wird.
    @param base Zielbasis, in der die Zahl number dargestellt werden soll.
*/
void print_convert(int number, int base)
{
    printf("Convert %4d to base %2d: %s\n", number, base, convert_to_base(number, base));
}
/*
    Testfaelle fuer convert_to_base.
*/
void test_convert_to_base()
{

    print_convert(0, 2);
    test_equal_s(convert_to_base(0, 2), "0");

    print_convert(16, 3);
    test_equal_s(convert_to_base(16, 3), "121");

    print_convert(16, 16);
    test_equal_s(convert_to_base(16, 16), "10");

    print_convert(100, 10);
    test_equal_s(convert_to_base(100, 10), "100");

    print_convert(0, 2);
    test_equal_s(convert_to_base(0, 2), "0");

    print_convert(10, 16);
    test_equal_s(convert_to_base(10, 16), "A");

    print_convert(100, 2);
    test_equal_s(convert_to_base(100, 2), "1100100");

    print_convert(20, 5);
    test_equal_s(convert_to_base(20, 5), "40");

    print_convert(1300300300, 36);
    test_equal_s(convert_to_base(1300300300, 36), "LI5Y4S");
}

// todo write purpose statement
void print_bits(int number)
{
    String bits = convert_to_base(number, 2);
    printf("0x%4x : %16s\n", number, bits);
}

void bit_operations()
{
    printsln("Bitmagic");
    // what does the following?
    /*
    & (Bitwise AND): Vergleicht bits von zwei Operatoren
    | (Bitwise OR): Gibt eine eins wieder,
                    wenn eines der beider operatoren eine eins ist,
                    annsonsten gibt es eine 0 wieder
    ^ (Bitwise XOR): Wenn beide Bits die Selben sind, dann wird 0 ausgegeben, sonnst 1
    << (Shift left): Verschiebt Bits von einer Binärzahl nach Links, je nach dem, welcher Value gegeben ist
    >> (Shift right): Das selbe nur nach rechts
    */
    printsln("&");
    int a = 0xaf;
    int b = 0xa5;

    int c = a & b;
    print_bits(a);
    print_bits(b);
    print_bits(c);

    printsln("|");
    a = 0xb1;
    b = 0x93;
    c = a | b;
    print_bits(a);
    print_bits(b);
    print_bits(c);

    printsln("^");
    a = 0xb1;
    b = 0x33;
    c = a ^ b;
    print_bits(a);
    print_bits(b);
    print_bits(c);

    printsln("<< und >>");
    a = 0x30;
    print_bits(a);
    a <<= 2;
    print_bits(a);
    a >>= 3;
    print_bits(a);
}

// todo
int set_bit(int value, int index, bool bit)
{
    if (bit == true)
    {
        return (~(1 << index) & value) | (true << index);
    }

    if (bit == false)
    {
        return (~(1 << index) & value) | (false << index);
    }
    return 0;
}

// todo
bool get_bit(int value, int index)
{
    int value1 = value >> index;
    int value2 = value1 & 1;

    if (value2 == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*
    Testfaelle fuer get_bit und set_bit
*/
void test_get_set_bit()
{
    int a = 0x77;
    // print_bits(a);

    test_equal_b(get_bit(a, 0), true);
    test_equal_b(get_bit(a, 1), true);
    test_equal_b(get_bit(a, 2), true);
    test_equal_b(get_bit(a, 3), false);
    test_equal_b(get_bit(a, 4), true);
    test_equal_b(get_bit(a, 5), true);
    test_equal_b(get_bit(a, 6), true);
    test_equal_b(get_bit(a, 7), false);
    test_equal_b(get_bit(a, 8), false);

    a = set_bit(a, 0, false);
    test_equal_i(a, 0x76);
    a = set_bit(a, 0, true);
    test_equal_i(a, 0x77);
    a = set_bit(a, 5, false);
    test_equal_i(a, 0x57);
    a = set_bit(a, 1, true);
    test_equal_i(a, 0x57);
    a = set_bit(a, 3, false);
    test_equal_i(a, 0x57);
}

// todo OPTIONAL
int extract_bits(int value, int start, int end)
{
    return value;
}

/*
    Testfaelle fuer extract_bits.
*/
void test_extract_bits()
{
    test_equal_s(convert_to_base(extract_bits(0x1805, 0, 4), 2), "101");
    test_equal_s(convert_to_base(extract_bits(0x1404, 8, 16), 2), "10100");
    test_equal_s(convert_to_base(extract_bits(0x1701, 12, 16), 2), "1");
    test_equal_s(convert_to_base(extract_bits(0x1503, 1, 9), 2), "10000001");
    test_equal_s(convert_to_base(extract_bits(0x1602, 0, 16), 2), "1011000000010");
    test_equal_s(convert_to_base(extract_bits(0xABCD, 16, 0), 2), "0");
    test_equal_s(convert_to_base(extract_bits(0xABCD, -1, 3), 2), "0");
    test_equal_s(convert_to_base(extract_bits(0xABCD, 4, 34), 2), "0");
}

int main(void)
{
    test_convert_to_base();
    /* Entfernen Sie Kommentierung der nachfolgenden Zeilen fuer Aufgabe 2
    printsln("------------------------------");
    bit_operations();
    printsln("------------------------------");
    test_get_set_bit();
    test_extract_bits();
    */
    return 0;
}