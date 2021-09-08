# Object-oriented C++

## Zadanie

1. <!-- .element: class="fragment fade-in" --> Zaproponuj właściwą abstrakcję (interfejs)
2. <!-- .element: class="fragment fade-in" --> Zastosuj dziedziczenie
3. <!-- .element: class="fragment fade-in" --> Napraw enkapsulację
4. <!-- .element: class="fragment fade-in" --> Użyj polimorfizmu, aby za pomocą wskaźnika na klasę bazową reprezentować dowolny typ samochodu

## Pytania

1. <!-- .element: class="fragment fade-in" --> Jak trzymać silniki? Przez wartość, referencję, czy wskaźnik?
2. <!-- .element: class="fragment fade-in" --> Czy jest problem diamentowy?
3. <!-- .element: class="fragment fade-in" --> Czy są wycieki pamięci?
4. <!-- .element: class="fragment fade-in" --> Czy kod jest testowalny?

## Praca domowa

You can work in groups or individually. Please fork the repo and submit a Pull Request after you have finished.

1. Create `InvalidGear` exception. It should be thrown when someone tries eg. change a gear from 5 to R. It should inherit from one of STL exceptions
2. Fix interfaces to be easy to use correctly and hard to use incorrectly (like `accelerate(-999)`)
3. (Optional) Write proper unit tests to this code.
4. Przeczytaj artykuł [SOLID czyli dobre praktyki w programowaniu obiektowym](https://www.samouczekprogramisty.pl/solid-czyli-dobre-praktyki-w-programowaniu-obiektowym/)
