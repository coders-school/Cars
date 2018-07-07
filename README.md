1. Przejrzyj zdefiniowane tam nagłówki. Używając vima napraw błąd kopipasty w ElectricCar.hpp
1. Zastosuj dziedziczenie i zdefiniuj prawidłową abstrakcję (interfejsy)
1. Napraw problem diamentowy
1. Napraw enkapsulację (hermetyzację)
1. Napisz własne implementacje do zdefiniowanych plików hpp wypisujące nazwę funkcji i przekazane do niej parametry
1. Napisz CMakeLists.txt do kompilacji
1. W main.cpp użyj polimorfizmu, aby za pomocą jednego obiektu można było reprezentować każdy samochód
1. Napisz wyjątek InvalidGear, który będzie rzucany gdy np. ktoś spróbuje zmienić bieg na wsteczny przy jeździe do przodu lub gdy ktoś spróbuje wrzucić 6 bieg, a samochód posiada ich 5. Wybierz odpowiedni wyjątek z biblioteki standardowej jako klasę bazową. Gdzie ten wyjątek powinien być złapany?
1. Zastanów się w jaki sposób obiekt klasy Engine powinien być trzymany w klasie Car - wartość, referencja, wskaźnik.

Praca domowa:
1. Popraw interfejsy według własnego uznania, aby były jak najmniej podatne na niewłaście użycie (np. accelerate(-999); )
1. Dodaj nowe klasy wyjątków, które będą rzucane w innych nietypowych sytuacjach. Spróbuj przewidzieć te nietypowe sytuacje.
