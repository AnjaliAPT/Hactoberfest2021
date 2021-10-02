public class TowerOfHanoi {
    static void towerOfHanoi(int n, char sourceDisk, char auxDisk, char destiDisk) {
        if (n == 0)
            return;
        towerOfHanoi(n - 1, sourceDisk, destiDisk, auxDisk);
        System.out.println("Disk" + n + " moved from rod " + sourceDisk + " to rod " + destiDisk);
        towerOfHanoi(n - 1, auxDisk, sourceDisk, destiDisk);
    }

    public static void main(String[] args) {
        towerOfHanoi(3, 'A', 'B', 'C');
    }
}
