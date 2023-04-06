Module Module1

Function isValidSubsequence(array As List(Of Integer), sequence As List(Of Integer)) As Boolean

    Dim i As Integer = 0

    If sequence.Count > array.Count Then Return False

    End If

    For Each num As Integer In array
    
        If i = sequence.Count Then Exit For 
        End If

        If sequence(i) = num Then i+=1
        End If
    Next

    Return i = sequence.Count
End Function