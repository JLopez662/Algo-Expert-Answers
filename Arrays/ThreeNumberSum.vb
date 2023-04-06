Imports System.Collections.Generic
Improts System.Linq

Module Module1

    Function ThreeNumberSum(ByVal array As List(Of Integer), ByVal targetSum As Integer) 
    As List(Of List(Of Integer))

        Dim Sum As New List(Of List(Of Integer))()

        array.Sort()

        Dim first As Integer = 0
        Dim index As Integer = 0, result As Integer = 0, pivot As Integer = 0

        For last As Integer = 1 To array.Count -1
            pivot = (array(first)) + (array(last))
            pivot = -pivot

            If array(first) <= pivot Then
                For i As Integer = 1 To last - 1
                    If pivot = array(i) AndAlso pivot <> array(first) 
                                        AndAlso pivot <> array(last) 
                    Then 

                        Sum.Add(New List(Of Integer)())
                        Sum(index).Add(array(first))
                        Sum(index).Add(pivot)
                        Sum(index).Add(array(last))
                        index += 1
                    End If
                Next

                If last = array.Count -1 Then
                    first += 1
                    last = first + 1
                End If
            End If
        Next 
        
        Return Sum
    End Function

    Sub Main()

        Dim array As New List(Of Integer)() From {12, 3, 1, 2, -6, 5, -8, 6}

        Dim targetSum As Integer = 0

        Dim result As List(Of List(Of Integer)) = ThreeNumberSum(array, targetSum)

        For Each item As List(Of Integer) In result
            Console.WriteLine("[{0}]", StringJoin(",", item))
        Next 
    End Sub
    
End Module



