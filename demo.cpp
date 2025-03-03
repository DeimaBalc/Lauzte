#include "lauzte.h"
#include <iostream>
#include <cassert>
#include <cmath>
#include <iomanip>

// Function to check if two doubles are approximately equal
bool approxEqual(double a, double b, double epsilon = 0.0001) {
    return std::abs(a - b) < epsilon;
}

// Test function for Taskas3D class
void testTaskas3D() {
    std::cout << "\n=== Testing Taskas3D Class ===\n";
    
    // Test constructor and getters
    Taskas3D t1(1.0, 2.0, 3.0);
    std::cout << "Created point: " << t1.to_string() << std::endl;
    assert(t1.getX() == 1.0);
    assert(t1.getY() == 2.0);
    assert(t1.getZ() == 3.0);
    std::cout << "Constructor and getters: PASSED\n";
    
    // Test default constructor
    Taskas3D t2;
    std::cout << "Default point: " << t2.to_string() << std::endl;
    assert(t2.getX() == 0.0);
    assert(t2.getY() == 0.0);
    assert(t2.getZ() == 0.0);
    std::cout << "Default constructor: PASSED\n";
    
    // Test keisk methods
    t2.setX(5.0);
    t2.setY(6.0);
    t2.setZ(7.0);
    std::cout << "After keiskX/Y/Z: " << t2.to_string() << std::endl;
    assert(t2.getX() == 5.0);
    assert(t2.getY() == 6.0);
    assert(t2.getZ() == 7.0);
    
    t2.setTaska(10.0, 11.0, 12.0);
    std::cout << "After keiskTaska: " << t2.to_string() << std::endl;
    assert(t2.getX() == 10.0);
    assert(t2.getY() == 11.0);
    assert(t2.getZ() == 12.0);
    std::cout << "Setter methods: PASSED\n";
    
    // Test atstumas method
    Taskas3D t3(3.0, 0.0, 0.0);
    Taskas3D t4(0.0, 4.0, 0.0);
    double dist = t3.atstumas(t4);
    std::cout << "Distance between " << t3.to_string() << " and " << t4.to_string() << ": " << dist << std::endl;
    assert(approxEqual(dist, 5.0));
    std::cout << "Distance calculation: PASSED\n";
}

// Test function for Lauzte3D class
void testLauzte3D() {
    std::cout << "\n=== Testing Lauzte3D Class ===\n";
    
    // Test default constructor
    Lauzte3D l1;
    std::cout << "Default line: " << l1.to_string() << std::endl;
    assert(l1.getN() == 1);
    assert(l1.getTaskas(0).getX() == 0.0);
    assert(l1.getTaskas(0).getY() == 0.0);
    assert(l1.getTaskas(0).getZ() == 0.0);
    std::cout << "Default constructor: PASSED\n";
    
    // Test constructor with parameters
    Taskas3D points[4] = {
        Taskas3D(0.0, 0.0, 0.0),
        Taskas3D(1.0, 0.0, 0.0),
        Taskas3D(1.0, 1.0, 0.0),
        Taskas3D(1.0, 1.0, 1.0)
    };
    
    Lauzte3D l2(4, points);
    std::cout << "Line with points: " << l2.to_string() << std::endl;
    assert(l2.getN() == 4);
    assert(l2.getTaskas(2).getX() == 1.0);
    assert(l2.getTaskas(2).getY() == 1.0);
    assert(l2.getTaskas(2).getZ() == 0.0);
    std::cout << "Constructor with parameters: PASSED\n";
    
    // Test copy constructor
    Lauzte3D l3 = l2;  // Copy constructor
    std::cout << "Copied line: " << l3.to_string() << std::endl;
    assert(l3.getN() == l2.getN());
    for (int i = 0; i < l3.getN(); i++) {
        assert(l3.getTaskas(i).getX() == l2.getTaskas(i).getX());
        assert(l3.getTaskas(i).getY() == l2.getTaskas(i).getY());
        assert(l3.getTaskas(i).getZ() == l2.getTaskas(i).getZ());
    }
    std::cout << "Copy constructor: PASSED\n";
    
    // Test setTaskas method
    l3.setTaskas(1, Taskas3D(5.0, 5.0, 5.0));
    std::cout << "After setting point: " << l3.to_string() << std::endl;
    assert(l3.getTaskas(1).getX() == 5.0);
    assert(l3.getTaskas(1).getY() == 5.0);
    assert(l3.getTaskas(1).getZ() == 5.0);
    std::cout << "setTaskas method: PASSED\n";
    
    // Test ilgis method for l2 (original points)
    double length = l2.ilgis();
    // Expected length: 1.0 + 1.0 + 1.0 = 3.0
    std::cout << "Length of line: " << length << std::endl;
    assert(approxEqual(length, 3.0));
    std::cout << "ilgis method: PASSED\n";
    
    // Test ilgis method for l3 (modified points)
    double length2 = l3.ilgis();
    // Distance from (0,0,0) to (5,5,5) is sqrt(75) = 8.66...
    // Distance from (5,5,5) to (1,1,0) is sqrt(32) = 5.66...
    // Distance from (1,1,0) to (1,1,1) is 1.0
    // Total: sqrt(75) + sqrt(32) + 1.0
    double expected = std::sqrt(75) + std::sqrt(57) + 1.0;
    std::cout << "Length of modified line: " << length2 << std::endl;
    std::cout << "Expected length: " << expected << std::endl;
    assert(approxEqual(length2, expected, 0.1));
    std::cout << "Modified ilgis calculation: PASSED\n";
    
    // Test boundary conditions
    Taskas3D outOfBoundsTest = l2.getTaskas(10);  // Out of bounds index
    std::cout << "Out of bounds access returns: " << outOfBoundsTest.to_string() << std::endl;
    // Should return the first point according to implementation
    assert(outOfBoundsTest.getX() == l2.getTaskas(0).getX());
    assert(outOfBoundsTest.getY() == l2.getTaskas(0).getY());
    assert(outOfBoundsTest.getZ() == l2.getTaskas(0).getZ());
    std::cout << "Boundary condition handling: PASSED\n";
}

int main() {
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "=== Starting Tests for Lauzte3D Program ===\n";
    
    // Test Taskas3D class
    testTaskas3D();
    
    // Test Lauzte3D class
    testLauzte3D();
    
    std::cout << "\n=== All Tests PASSED ===\n";
    return 0;
}