# COM portunuza bağlanın
$port = new-Object System.IO.Ports.SerialPort COM4, 19200, None, 8, one

# Portu açın
$port.Open()

# Veri okuma döngüsü, kullanıcı müdahale edene kadar devam eder
try {
    while ($true) {
        if ($port.BytesToRead -gt 0) {
            $data = $port.ReadLine()
            echo $data
        } else {
            Start-Sleep -Milliseconds 100  # Eğer veri yoksa, CPU kullanımını azaltmak için kısa bir süre bekleyin
        }
    }
} catch {
    echo "Bir hata oluştu: $_"
} finally {
    $port.Close()  # Hata oluşsa da oluşmasa da portu kapat
    echo "Port kapandı."
}