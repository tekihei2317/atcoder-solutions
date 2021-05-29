class Graph
  def initialize(n, m)
    @n, @m = n, m
    @list = inputAdjacentList(n, m)
  end

  def solve(colors)
    @answers = []
    @counts = Array.new(10 ** 5 + 1, 0)
    dfs(0, -1, colors)

    @answers
  end

  def dfs(v, parent, colors)
    @counts[colors[v]] += 1
    @answers << v + 1 if @counts[colors[v]] == 1

    @list[v].each do |u|
      dfs(u, v, colors) if u != parent
    end

    @counts[colors[v]] -= 1
  end

  private

  def inputAdjacentList(n, m)
    list = Array.new(n) { [] }
    m.times do
      a, b = gets.split(" ").map(&:to_i)
      list[a - 1] << b - 1
      list[b - 1] << a - 1
    end
    list
  end
end

n = gets.to_i
colors = gets.split(" ").map(&:to_i)
graph = Graph.new(n, n - 1)

answers = graph.solve(colors)
puts answers.sort.join("\n")
