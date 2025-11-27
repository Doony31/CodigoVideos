// funcion que cambia del fondo de los caracteres
void colorFondo(int opc) {
    switch (opc) {
    case 0: Console::BackgroundColor = ConsoleColor::Black; break;
    case 1: Console::BackgroundColor = ConsoleColor::DarkBlue; break;
    case 2: Console::BackgroundColor = ConsoleColor::DarkGreen; break;
    case 3: Console::BackgroundColor = ConsoleColor::DarkRed; break;
    case 4: Console::BackgroundColor = ConsoleColor::White; break;
    case 5: Console::BackgroundColor = ConsoleColor::DarkYellow; break;
    case 6: Console::BackgroundColor = ConsoleColor::Gray; break;
    case 7: Console::BackgroundColor = ConsoleColor::DarkGray; break;
    case 8: Console::BackgroundColor = ConsoleColor::Blue; break;
    case 9:  Console::BackgroundColor = ConsoleColor::Green; break;
    case 10: Console::BackgroundColor = ConsoleColor::Cyan; break;
    case 11: Console::BackgroundColor = ConsoleColor::Red; break;
    case 12: Console::BackgroundColor = ConsoleColor::Magenta; break;
    case 13: Console::BackgroundColor = ConsoleColor::Yellow; break;
    case 14: Console::BackgroundColor = ConsoleColor::DarkMagenta; break;
    default: Console::BackgroundColor = ConsoleColor::Black; break;
    }
}

// funcion que cambia el color de los caracteres
void color(int opc) {
    switch (opc) {
    case 0: Console::ForegroundColor = ConsoleColor::Black; break;
    case 1: Console::ForegroundColor = ConsoleColor::DarkBlue; break;
    case 2: Console::ForegroundColor = ConsoleColor::DarkGreen; break;
    case 3: Console::ForegroundColor = ConsoleColor::DarkRed; break;
    case 4: Console::ForegroundColor = ConsoleColor::White; break;
    case 5: Console::ForegroundColor = ConsoleColor::DarkYellow; break;
    case 6: Console::ForegroundColor = ConsoleColor::Gray; break;
    case 7: Console::ForegroundColor = ConsoleColor::DarkGray; break;
    case 8: Console::ForegroundColor = ConsoleColor::Blue; break;
    case 9: Console::ForegroundColor = ConsoleColor::Green; break;
    case 10: Console::ForegroundColor = ConsoleColor::Cyan; break;
    case 11: Console::ForegroundColor = ConsoleColor::Red; break;
    case 12: Console::ForegroundColor = ConsoleColor::Magenta; break;
    case 13: Console::ForegroundColor = ConsoleColor::Yellow; break;
    case 14: Console::ForegroundColor = ConsoleColor::DarkMagenta; break;
    default: Console::BackgroundColor = ConsoleColor::Black; break;
    }
}