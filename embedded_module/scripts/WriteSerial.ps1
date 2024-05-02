# COM portunuza bağlanın
$port = new-Object System.IO.Ports.SerialPort COM3, 9600, None, 8, one

# Portu açın
$port.Open()

# Kullanıcıdan giriş al
Write-Host "Enter resistance angle (type 'exit' to exit):"
do {
    $input = Read-Host "Message"
    if ($input -ne 'exit') {
        $port.WriteLine($input)  # Mesajı Arduino'ya gönder
        Write-Host "Angle: $input"
    }
} while ($input -ne 'exit')

# Portu kapat
$port.Close()
Write-Host "Connection is closed."