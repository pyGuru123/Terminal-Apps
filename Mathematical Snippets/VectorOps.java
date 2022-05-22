class Vector{
    int x;
    int y;
    int z;
    
    Vector(int x, int y, int z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }
    
    @Override public String toString() {
        return "Vector(" + x + "," + y + "," + z + ")";
    }
    
    Vector add(Vector v) {
        int newx = this.x + v.x;
        int newy = this.y + v.y;
        int newz = this.z + v.z;
        Vector vector = new Vector(newx, newy, newz);
        return vector;
    }
    
    Vector sub(Vector v) {
        int newx = this.x - v.x;
        int newy = this.y - v.y;
        int newz = this.z - v.z;
        Vector vector = new Vector(newx, newy, newz);
        return vector;
    }
    
    Vector mul(int c) {
        // Method overloading
        int newx = this.x * c;
        int newy = this.y * c;
        int newz = this.z * c;
        Vector vector = new Vector(newx, newy, newz);
        return vector;
    }
    
    int mul(Vector v) {
        // Method overloading ( dot product)
        return this.x * v.x + this.y * v.y + this.z * v.z;
    }
    
    double magnitude() {
        // this holds current instance
        return Math.sqrt(this.mul(this));
    }
}

class VectorOps {
    public static void main(String args[]) {
        Vector v1 = new Vector(3, 5, 2);
        Vector v2 = new Vector(4, 4, 1);
        System.out.println(v1);
        System.out.println(v2);
        System.out.println(v1.add(v2));
        System.out.println(v1.sub(v2));
        System.out.println(v1.mul(3));
        System.out.println(v1.mul(v2));
        System.out.println(v1.magnitude());
    }
}