$ZipExcludes = @('*\.vs\*', '*\x64\*', '*.zip')
$DirExcludes = @('.git')
$ZipFileName = '學號_姓名.zip'

$DirsToZip = Get-ChildItem -Attributes Directory -Exclude $DirExcludes -Name

$CurrentPath = Get-Location
foreach ($Dir in $DirsToZip)
{
    $FileList = Get-ChildItem $Dir -File -Recurse | where {
        $FN = $_.FullName 
        -not ($ZipExcludes | where {$FN -like $_})
        }
    Write-Output "Archiving $Dir -> $Dir/$ZipFileName"
    Get-ChildItem -File -Recurse -Filter $ZipFileName | Remove-Item
    Try
    {
        $WriteArchive = [IO.Compression.ZipFile]::Open("$CurrentPath/$Dir/$ZipFileName", 'Create')
        foreach ($File in $FileList)
        {
            $RelativePath = (Resolve-Path -LiteralPath $File.FullName -Relative) -replace '^.\\'
            Try
            {
                [IO.Compression.ZipFileExtensions]::CreateEntryFromFile($WriteArchive, $File.FullName, $RelativePath, 'Optimal') | Out-Null
            }
            Catch
            {
                Write-Warning "$RelativePath could not be archived. `n $($_.Exception.Message)"
            }
        }
    }
    Catch [Exception]
    {
        Write-Error $_.Exception
    }
    Finally
    {
        $WriteArchive.Dispose()
    }
}
