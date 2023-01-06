void swap(const int *(&i), const int *(&j)) {
    const int *temp = i;
    i = j;
    j = temp;
}
