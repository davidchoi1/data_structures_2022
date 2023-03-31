int main(int argc, char const *argv[])
{
    int left{0};
    int right{1};

    left = (right > left) ? right : left;                                   // if right > left is true, assign value right, if false, assign value left

    return 0;
}
