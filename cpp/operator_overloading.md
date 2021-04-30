# Surcharge des opérateurs
On peut redéfinir les opérateurs pour des classes/structs que le programmeur à définies uniquement

```cpp
Complex c1(2, 3);
Complex c2(1, 2);
Complex c3();


// Sans surcharge, avec une méthode add
c3 = c1.add(c2);

// Sans surcharge de << sur la class Complex
cout << c3.show() << endl;


// Avec surcharge de l'opérateur "+"
c3 = c1 + c2;

// Avec surcharge de << sur la class Complex
cout << c3 << endl;
```

*output*
```
Re: 3, Im: 5
Re: 3, Im: 5
```

# Les différents opérateurs
On peut surcharger les opérateurs 53 suivants:  
`=`
`+`
`-`
`*`
`/`
`^`
`%`
`=`
`==`
`+=`
`-=`
`/=`
`^=`
`%=`
`<`
`<=`
`>`
`>=`
`<<`
`>>`
`<<=`
`>>=`
`++`
`--`
`&`
`|`
`!`
`&=`
`|=`
`!=`
`,`
`[]`
`()`
`&&`
`||`
`~`
`xor`
`xor_eq`
`and`
`and_eq`
`or`
`or_eq`
`not`
`not_eq`
`bitand`
`bitor`
`compl`

La surcharge des opérateurs suivants est **dangereuse**  
`->`
`->*`
`new`
`new[]`
`delete`
`delete[]`

Les 5 opérateurs suivants **ne peuvent pas être surchargés**  
`.`
`.*`
`::`
`?:`
`sizeof`

# Méthode de surcharge
Pour chaque opérateur `X` la méthode `operatorX(...)` peut être surchargée

```cpp
c1 + c2;

// Est transformée en:

c1.operator+(c2);
```

```cpp
c1 = c2;

// Est transformée en:

c1.operator=(c2);
```


```cpp
c1 = c2 = c3;

// Est transformée en:

c1.operator=(c2.operator=(c3));
```

# Méthode membre / non membre
On peut surcharger un opérateur avec une fonction membre de la classe ou non membre

## Méthode membre
```cpp
!obj;

// Equivaut à:

obj.operator!();
```

```cpp
c1 + c2;

// Equivaut à:

c1.operator+(c2);
```

## Méthode non membre
```cpp
!obj;

// Equivaut à:

operator!(obj);
```

```cpp
c1 + c2;

// Equivaut à:

operator+(c1, c2);
```

# Définition de la surcharge
## Membre

**NON COMMUTATIF**
```cpp
Complex c1, c2, c3;
int x, y;

c = c1 + c2;  // OK: c = c1.operator+(c2);
c = c1 + y;   // OK: c = c1.operator+(Complex(y));

// ERREUR: x n'est pas un objet Complex
// Pas de conversion implicite
// x.operator+(...) n'existe pas
c = x + c2;   
```

```cpp
// c = a + ib
class Complex
{
  private:
    double a;
    double b;

  public:
    Complex operator+(const Complex &c) const;
    // 1er const: L'objet en paramètre n'est pas modifié
    // 2ème const: this n'est pas modifié
};

Complex Complex::operator+(const Complex &c) const
{
  return Complex(
    this->a + c.a,
    this->b + c.b
  );
}
```

## Non membre

**COMMUTATIF**
```cpp
Complex c1, c2, c3;
int x, y;

c = c1 + c2;  // OK: c = operator+(c1, c2);
c = c1 + y;   // OK: c = operator+(c1, Complex(y));
c = x + c2;   // OK: c = operator+(Complex(x), c2);

// ATTENTION
c = x + y   // c = operator+(Complex(x + y));
```

### Non membre simple
```cpp
// c = a + ib
class Complex
{
  private:
    double a;
    double b;

  public:
    double getA() const;
    void setA(double value);

    double getB() const;
    void setB(double value);
};

Complex operator+(
  const Complex &c1,
  const Complex &c2
)
{
  return Complex(
    c1.getA() + c2.getA(),
    c1.getB() + c2.getB(),
  );
}
```

### Non membre `friend`
```cpp
// c = a + ib
class Complex
{
  private:
    double a;
    double b;

  public:
    friend Complex operator+(
      const Complex &c1,
      const Complex &c2
    );
};

Complex operator+(
  const Complex &c1,
  const Complex &c2
)
{
  return Complex(
    c1.a + c2.a,
    c1.b + c2.b,
  );
}
```

# Surcharge de `<<` et `>>`
La surcharge **n'est pas une fonction membre de la classe concernée**

## Surcharge de `<<`
```cpp
ostream& operator<<(ostream &s, const Complex &c)
{
  return s << c.getA() << " + i " << c.getB() << endl;
}
```

### Note sur `<<`
```cpp
cout << c1 << c2 << endl;
```

Equivaut à 

```cpp
operator<<(operator<<(operator<<(cout, c1), p2), endl);
```

## Surcharge de `>>`
Par exemple si l'on veut entrer un `Complex` au clavier sous le format:  
"`(a, b)`"
```cpp
istream& operator>>(istream &i, const Complex &c)
{
  char c;
  i >> control_char;
  // A écrit:       "("
  // control_char:  '('
  // c:             Complex(?, ?)

  if (control_char == '(')
  {
    i >> c.a >> control_char;
    // A écrit:       "2,"
    // control_char:  ','
    // c:             Complex(2, ?)

    if (control_char == ",")
    {
      i >> c.b >> control_char;
      // A écrit:       "3)"
      // control_char:  ')'
      // c:             Complex(2, 3)
      
      if (control_char == ")")
      {
        return i;
      }
    }
  }

  cerr << "Error\n";
  exit(-1);
}
```

# Surcharge de `=`
On doit différencier 2 cas:
```cpp
Complex c1;
Complex c2 = c1;  // Constructeur par recopie
c1 = c2;          // Affectation operator=
```

```cpp
Complex &Complex()::operator=(const Complex &c)
{
  // Recopie en profondeur
  return *this;
}
```

```cpp
Complex c1, c2, c3;
c1 = c2 = c3;

c1.operator=(c2.operator=(c3));
```

# Surcharge des opérateur de conversion
```cpp
class Complex
{
  private:
    double a = 0;
    double b = 0;

  public:
    // Conversion: int -> Complex
    // Constructeur
    Complex(int a)
    {
      this->a = a;
    }

    // Conversion: Complex -> int
    // Surcharge d'opérateur de conversion
    operator int()
    {
      return this->a;
    }
};
```

```cpp
Complex c(1, 2);
int(c) // -> 1
```

# Surcharge de `++` et `--`

## Post/Pré fixé
Moyen mnémotechnique: **PostInt** (post'it)

### Préfixé
- Le type de retour (de `res`) est une référence `Complex&`
- `c.operator++()` n'a pas d'arguments

```cpp
Complex c(0, 0);
++c;

// Le type de retour (de res) est une référence Complex&
// c.operator++() n'a pas d'arguments
Complex &res = c.operator++();
```

### Postfixé
- Le type de retour (de `res`) est un objet `Complex`
- `c.operator++()` peut avoir un argument `int`

```cpp
Complex c(0, 0);
c++;

// Le type de retour (de res) est un objet Complex
// c.operator++() peut avoir un argument int
Complex res = c.operator++(2);
```

## Exemple
```cpp
class Complex
{
  private:
    double a = 0;
    double b = 0;

  public:
    Complex &operator++()
    {
      ++a;
      return *this;
    }


    Complex operator++(int inc)
    {
      Complex temp = *this;
      a += inc;

      // Retourne une version inchangée de this
      // car c'est une POST-incrémentation
      return temp;
    }
};
```

# Liste des surcharges utiles
## Membres
```cpp
// p == q
bool operator==(const ClassName&) const;

// p < q
bool operator<(const ClassName&) const; 

// p = q
ClassName& operator=(const ClassName&); 

// p += q
ClassName& operator+=(const ClassName&); 

// ++p
ClassName& operator++();

// p++
ClassName operator++(int);

// p *= x
ClassName& operator*=(const other_type); 

// q = -p
ClassName operator-() const; 

// vector[5]
<type>& operator[](int); 
```

## Non membres
```cpp
// std::cout << p
ostream& operator<<(ostream&, const ClassName&);

// 3.14 * p
ClassName operator*(const other_type, const ClassName&); 

// r = p - q
ClassName operator-(const ClassName &, const ClassName&); 
```

# Big Rule Of Three
Si vous devez définir l'une des trois fonctions de base, que sont le **constructeur de copie**, l'**opérateur d'affectation** ou le **destructeur**, alors **vous devez définir les trois**.

# Foncteur
Si on surcharge `operator()` on peut utiliser la classe comme une fonction

```cpp
class Linear
{
  private:
    double a;
    double b;

  public:
    Linear(double a, double b) : a(a), b(b) {}

    double operator()(double x) const
    {
      return a * x + b
    }
};
```

```cpp
Linear f(2, 1);   // 2x + 1
f(3.5)            // 8
```
