# Define the GF(16) field using the irreducible polynomial x^4 + x + 1
F = GF(2**4, name='a', modulus=x^4 + x + 1)

# Function to add two elements in GF(16)
def gf16_add(a, b):
    return a + b

# Function to multiply two elements in GF(16)
def gf16_multiply(a, b):
    return a * b

# Function to find the inverse of an element in GF(16)
def gf16_inverse(a):
    return a^(-1) if a != 0 else 0

# Function to convert a polynomial to an integer
def poly_to_int(poly):
    return int(sum([int(coef) * (2 ** i) for i, coef in enumerate(poly.list())]))

# Test the GF(16) operations
a = F.fetch_int(7)  # Element 7 in GF(16)
b = F.fetch_int(3)  # Element 3 in GF(16)

# Perform operations
add_result = gf16_add(a, b)
mul_result = gf16_multiply(a, b)
inv_result = gf16_inverse(a)

# Convert to integer
poly_a_as_int = poly_to_int(a.polynomial())
poly_b_as_int = poly_to_int(b.polynomial())

add_result_as_int = poly_to_int(add_result.polynomial())
mul_result_as_int = poly_to_int(mul_result.polynomial())
inv_result_as_int = poly_to_int(inv_result.polynomial())

# Output the results
print("Addition (a + b) in GF(16):", add_result)
print("Multiplication (a * b) in GF(16):", mul_result)
print("Inverse of a in GF(16):", inv_result)
print("Polynomial representation of a as integer:", poly_a_as_int)
print("Polynomial representation of b as integer:", poly_b_as_int)

print("Addition (a + b) in GF(16):", add_result_as_int)
print("Multiplication (a * b) in GF(16):", mul_result_as_int)
print("Inverse of a in GF(16):", inv_result_as_int)


