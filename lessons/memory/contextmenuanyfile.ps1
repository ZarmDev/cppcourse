Add-Type -AssemblyName System.Windows.Forms

# Create SaveFileDialog
$dialog = New-Object System.Windows.Forms.SaveFileDialog
$dialog.Title = "Create New File"
$dialog.InitialDirectory = [Environment]::GetFolderPath("Desktop")
$dialog.Filter = "Text File (*.txt)|*.txt|Markdown File (*.md)|*.md|Batch File (*.bat)|*.bat|All Files (*.*)|*.*"
$dialog.OverwritePrompt = $false

# Show dialog
if ($dialog.ShowDialog() -eq "OK") {
    $path = $dialog.FileName
    if (-not (Test-Path $path)) {
        New-Item -Path $path -ItemType File | Out-Null
        Write-Host "Created file: $path"
    } else {
        Write-Host "File already exists: $path"
    }
}
