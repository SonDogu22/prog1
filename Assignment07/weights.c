/*
Compile: make weights
Run: ./weights
*/

#include "base.h"

// 1 lb = 0.45359237 kg

typedef enum unit_e
{
    G,
    KG,
    T,
    LB
} Unit;

typedef struct weight_s
{
    double amount;
    Unit unit;
} Weight;

Weight make_weight(double amount, Unit unit)
{
    // todo
    Weight w = {amount, unit};
    return w;
}

bool test_within_weight(int line, Weight a, Weight e, double tolerance)
{
    bool x = base_test_within_d(__FILE__, line, a.amount, e.amount, tolerance);
    bool u = base_test_equal_i(__FILE__, line, a.unit, e.unit);
    return x && u;
}

void print_weight(Weight w)
{
    // todo

    // printf("%.2f %\n",w.amount, w.unit);

    switch (w.unit)
    {
    case G:
        printf("%.2f G\n", w.amount);
        break;
    case KG:
        printf("%.2f KG\n", w.amount);
        break;
    case T:
        printf("%.2f T\n", w.amount);
        break;
    case LB:
        printf("%.2f LB\n", w.amount);
        break;

    default:
        break;
    }
}

void print_weight_test()
{
    print_weight(make_weight(1234, G));
    print_weight(make_weight(4.749, KG));
    print_weight(make_weight(3.1001, T));
    print_weight(make_weight(5.40006, LB));
}

// Weight, Unit -> Weight
// Convert weight to the given target unit.
Weight to_unit(Weight w, Unit target_unit)
{
    // todo
    if (w.unit != G)
    {
        switch (w.unit)
        {
        case KG:
            w.amount *= 1000;
            w.unit = G;
            to_unit(w, target_unit);
            break;
        case T:
            w.amount *= 1000000;
            w.unit = G;
            to_unit(w, target_unit);
            break;
        case LB:
            w.amount *= 453.6;
            w.unit = G;
            to_unit(w, target_unit);
            break;

        default:
            break;
        }
    }

    switch (target_unit)
    {
    case G:
        return w;
        break;

    case KG:
        w.amount /= 1000;
        w.unit = KG;
        return w;
        break;
    case T:
        w.amount /= 1000000;
        w.unit = T;
        return w;
        break;
    case LB:
        w.amount /= 453.6;
        w.unit = LB;
        return w;
        break;

    default:
        break;
    }

    return w;
}

void to_unit_test(void)
{
    test_within_weight(__LINE__, to_unit(make_weight(1000, G), KG), make_weight(1, KG), 1e-6);
    test_within_weight(__LINE__, to_unit(make_weight(2000, G), KG), make_weight(2, KG), 1e-6);
    test_within_weight(__LINE__, to_unit(make_weight(1000, KG), T), make_weight(1, T), 1e-6);
    test_within_weight(__LINE__, to_unit(make_weight(1, LB), G), make_weight(453.6, G), 1e-6);
    test_within_weight(__LINE__, to_unit(make_weight(1, LB), KG), make_weight(0.4536, KG), 1e-6);
    test_within_weight(__LINE__, to_unit(make_weight(0.5, T), G), make_weight(500000, G), 1e-6);

    // todo: add tests (at least 5)
}

// Weight, Weight -> int
// Compares two weights. Returns 0 if the two weights are equal,
// -1 if w is smaller than v and +1 otherwise.
int compare(Weight w, Weight v)
{
    // todo
    w = to_unit(w,G);
    v = to_unit(v,G);

    if (w.amount > v.amount)
    {
        return 1;
    }

    if (w.amount < v.amount)
    {
        return -1;
    }

    if (w.amount == v.amount)
    {
        return 0;
    }

    return 0;
}

void compare_test(void)
{
    test_equal_i(compare(make_weight(1000, G), make_weight(1, KG)), 0);
    // todo: add tests (at least 5)
	test_equal_i(compare(make_weight(1, LB), make_weight(1, KG)), -1);
	test_equal_i(compare(make_weight(900, G), make_weight(1, KG)), -1);
	test_equal_i(compare(make_weight(5, T), make_weight(5000, KG)), 0);
	test_equal_i(compare(make_weight(1000, G), make_weight(100, T)), -1);
	test_equal_i(compare(make_weight(1000, KG), make_weight(1, LB)), 1);
}



int main(void)
{
    print_weight_test();
    to_unit_test();
    compare_test();
    return 0;
}
