int ternarySearch(int left, int right) {
    while (right - left >= 3) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        if (func(mid1) < func(mid2)) {
            right = mid2;
        } else {
            left = mid1;
        }
    }

    int minValue = func(left);
    for (int i = left + 1; i <= right; ++i) {
        minValue = min(minValue, func(i));
    }

    return minValue;
}

double ternarySearch(double left, double right, double error) {
    while (right - left > error) {
        double mid1 = left + (right - left) / 3;
        double mid2 = right - (right - left) / 3;
        double f_mid1 = func(mid1);
        double f_mid2 = func(mid2);

        if (f_mid1 < f_mid2) {
            right = mid2;
        } else {
            left = mid1;
        }
    }

    return (left + right) / 2;
}
