class flowergame{
    public long flowerGame(int n, int m) {
        int odd1 = (m + 1) / 2;
        int even1 = m / 2;
        int odd2 = (n + 1) / 2;
        int even2 = n / 2;
        return 1L * odd1 * odd2 + 1L * even1 * even2;
    }
}


