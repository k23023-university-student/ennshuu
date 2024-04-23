class TestApp {
    public static void main(String[] args) {
        int a = 0;
        System.out.print(a++ + ", ");
        System.out.print(++a + ", ");
        System.out.print(a-- + ", ");
        System.out.print((a += 4) + ", ");
        System.out.print((a -= 6) + ", ");
        System.out.print((a += 12) + ", ");
        System.out.print(--a + ";");
    }
}
