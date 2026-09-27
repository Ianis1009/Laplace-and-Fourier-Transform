# Numerical Laplace Transform in C

## Overview

This project implements a **numerical approximation of the Laplace Transform** in pure C, combining concepts from:

* Mathematical Analysis (definite integrals)
* Complex Numbers
* Numerical Integration
* Signal Processing
* Algorithmic Sorting (`qsort`)

The program evaluates the Laplace Transform:

$$
F(s) = \int_0^{\infty} f(t)e^{-st}dt
$$

using a **finite interval approximation** and explores different values of:

$$
s = \sigma + i\omega
$$

---

## Mathematical Background

The Laplace Transform is defined as:

$$
F(s) = \int_0^\infty f(t)e^{-st}dt
$$

Where:

* $s = \sigma + i\omega$
* $e^{-st} = e^{-\sigma t}(\cos(\omega t) - i\sin(\omega t))$

This allows us to separate the transform into:

* Real part → cosine integral
* Imaginary part → sine integral

---

## Implementation Details

### 1. Numerical Integration

We approximate the integral using a simple Riemann sum:

$$
\int_0^T f(t)dt \approx \sum f(t_i)\Delta t
$$

Where:

* $T$ is a finite cutoff
* $N$ is the number of samples

---

### 2. Complex Representation

We use a struct:

```c
typedef struct {
    double re, im;
} Complex;
```

---

### 3. Function Used

The test function is:

$$
f(t) = e^{-t} \sin(5t)
$$

This ensures:

* convergence
* oscillatory behavior
* non-trivial spectrum

---

### 4. Spectral Exploration

We compute the transform for multiple values of:

* $\sigma \in [0.5, 2.5]$
* $\omega \in [1, 10]$

---

### 5. Sorting Results

We sort results using `qsort` based on amplitude:

```c
qsort(results, n, sizeof(Result), cmp);
```

This allows identification of **dominant Laplace components**.

---

## Output

Example:

```
Top Laplace components:
sigma=1.00, omega=5.00, amplitude=...
sigma=0.50, omega=5.00, amplitude=...
```

---

## Applications

* Signal processing
* Control systems
* Differential equations
* Physics simulations
* Electrical engineering

---

## Compilation

```bash
gcc main.c -o laplace -lm
./laplace
```

---

## Conclusion

This project demonstrates how **advanced mathematical concepts** like the Laplace Transform can be implemented from scratch using low-level programming in C.

It bridges the gap between:

* theory (analysis, complex numbers)
* and practice (numerical computation, algorithms)

---

# Numerical Fourier Transform in C

## Overview

This project implements a **numerical approximation of the Continuous Fourier Transform** using pure C.

It combines core concepts from:

* Mathematical Analysis (definite integrals)
* Complex Numbers
* Trigonometry
* Numerical Methods
* Signal Processing
* Algorithmic Sorting (`qsort`)

The program analyzes a time-domain signal and extracts its **dominant frequency components**.

---

## Mathematical Background

The Continuous Fourier Transform is defined as:

$$
F(\omega) = \int_{0}^{T} f(t), e^{-i\omega t} , dt
$$

Using Euler’s formula:

$$
e^{-i\omega t} = \cos(\omega t) - i\sin(\omega t)
$$

We can rewrite the transform as:

* Real part:
  $$
  \int f(t)\cos(\omega t),dt
  $$

* Imaginary part:
  $$
  \int f(t)\sin(\omega t),dt
  $$

---

## Implementation Details

### 1. Signal Definition

We analyze a composite signal:

$$
f(t) = \sin(2\pi \cdot 3t) + 0.7 \cdot \sin(2\pi \cdot 7t)
$$

This ensures:

* multiple frequencies
* clear spectral peaks
* realistic signal behavior

---

### 2. Numerical Integration

We approximate the integral using a Riemann sum:

$$
\int_0^T f(t),dt \approx \sum f(t_i)\Delta t
$$

Where:

* $T$ = total time window
* $N$ = number of samples

---

### 3. Complex Representation

We define a custom complex type:

```c
typedef struct {
    double re, im;
} Complex;
```

---

### 4. Frequency Sweep

We evaluate the transform for:

$$
\omega_k = 2\pi k, \quad k = 1,2,...,50
$$

This allows us to detect dominant frequencies in the signal.

---

### 5. Amplitude Extraction

We compute the magnitude:

$$
|F(\omega)| = \sqrt{Re^2 + Im^2}
$$

This represents the **energy contribution** of each frequency.

---

### 6. Sorting (Key Feature)

We use `qsort` to rank frequencies by importance:

```c
qsort(results, n, sizeof(Result), cmp);
```

Comparator:

* sorts by amplitude (descending)
* highlights dominant spectral components

---

## Example Output

```
Top Fourier components:
k = 3, amplitude ≈ high
k = 7, amplitude ≈ high
```

These correspond exactly to the frequencies used in the signal definition.

---

## Complexity

* Time complexity: **O(N × K)**
* Where:

  * N = samples
  * K = number of frequencies

---

## Compilation & Run

```bash
gcc main.c -o fourier -lm
./fourier
```


