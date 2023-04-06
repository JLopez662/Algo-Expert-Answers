Module Module1

    Function NonConstructibleChange(coins As List(Of Integer)) As Integer

        coins.Sort()

        Dim maxChange As Integer = 0
        Dim nonchange As Integer = 0

        For Each coin In coins
            If coin <= maxChange +1 Then maxChange += coin

            Else
                nonChange = maxChange + 1
                Return nonChange

            End If
        Next 

        Return maxChange +1

    End Function

    Sub Main()

        Dim coins As New List(Of Integer) From {5, 7, 1, 1, 2, 3, 22}

        Dim result As Integer = NonConstructibleChange(coins)

        Console.WriteLine("Result: " &result)

    End Sub
    
End Module

