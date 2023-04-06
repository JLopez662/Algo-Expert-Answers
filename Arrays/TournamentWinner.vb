Imports System.Collections.Generic

Module Module1

    Function TournamentWinner(competitions As List(Of List(Of String) ), results As List(Of Integer) ) As String

        Dim round As Integer = 0
        Dim participants As New Dictionary(Of String, Integer)()
        Dim maxScore As Integer = 0
        Dim winner As String = ""

        For i As Integer = 0 To results.Count - 1

            If results(i) = 0 Then 

                If Not participants.ContainsKey(competitions(i)(1)) Then
                    participants.Add(competitions(i)(1), 0)
                End If

                participants.Add(competitions(i)(1)) += 1

            Else
                If Not participants.ContainsKey(competitions(i)(0)) Then
                    participants.Add(competitions(i)(0), 0)
                End If

                participants(competitions(i)(0)) += 1

            End If
        Next 

        For Each im As KeyValuePair(Of String, Integer) In participants
            If im.Value > maxScore Then
                maxScore = im.Value
                winner = im.Key
            End If
        Next

        Return winner

    End Function

    Sub Main()

        Dim competitions As New List(Of List(Of String)) From{
            New List(Of String) From {"HTML", "C#"},
            New List(Of String) From {"C#", "Python"},
            New List(Of String) From {"Python", "HTML"}
        }

        Dim result As New List(Of Integer) From {0, 0, 1}

        Dim winner As String = TournamentWinner(competitions, results)

        Console.WriteLine("Winner: " & winner)

    End Sub
End Module

