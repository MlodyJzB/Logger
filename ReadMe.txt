1. Autor: Jakub Cimochowski AiR 104
2. Biblioteka Logger zawiera klasy 
- Loggers - kolekcję z wiadomościami klasy IMessage przechowywane jako wskaźniki
- IMessage - klasa wiadomości
- FanSpeedMessage - klasa dziedzicząca po IMessage (komunikaty prędkości wentylatorów)
- UsbDeviceMessage - klasa dziedzicząca po IMessage (komunikaty portów USB)
3. Środowiska: VisualStudio
4. Testowanie: Native Unit Test z użyciem funkcji AreEqual, AreNotEqual
5.
Klasa IMessage:
- setPriority() - ustawia priorytet po indeksie
- getPriority() - zwraca priorytet wiadomości
- getAsStr() - zwraca komunikat tekstowy jako string
- setTimeAdded() - ustawia czas dodania do kolekcji na bierzący moment
- getTimeAdded() - zwraca czas dodania do kolekcji

Klasa UsbDeviceMessage:
- getDeviceName() - zwraca nazwę urządzenia
- getOperation() - zwraca nazwę operacji
- getPort() - zwraca numer portu

FanSpeedMessage:
- getPercentage() - zwraca procentową wartość prędkości wentylatorów
- getOperation() - zwraca wiadomość czy prędkość wentylatorów została zmniejszona czy zwiększona
 
Klasa Loggers:

- add - dodaje wiadomości do kolekcji
- getMessagePtr - zwraca wiadomości po indeksie w kolejności od najnowszej, indeks od 0
- klasa ErrorIterator - iteruje po wiadomościach z priorytetem "Error", zaimplementowana operacja ++
